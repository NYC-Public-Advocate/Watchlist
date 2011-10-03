/**
 * @author Remy Sharp
 * @date 2008-02-25
 * @url 
 * @license Creative Commons License - ShareAlike http://creativecommons.org/licenses/by-sa/3.0/
 */
(function ($) {

$.fn.visited = function (fn) {
    var iframe = document.createElement('iframe'), 
        links = this, 
        body = $('body'), 
        i, 
        win, 
        visitedList = {},
        filter;

    // we need the iframe visible, otherwise getComputedStyle doesn't work
    iframe.style.position = 'absolute';
    iframe.style.left = '-1000px';
    iframe.height = '1';
    iframe.width = '1';
    iframe.id = 'visitedIF';
    
    body.append(iframe);
    win = iframe.contentDocument || iframe.contentWindow.document;

    // insert the HTML
    win.write(iframeHeader());
    for (i = 0; i < links.length; i++) {
        win.write('<a href="' + links[i].href + '">' + links[i].href + '</a>');
    }
    win.write(iframeFooter());
    win.close();

    // find the links which are green rgb(0, 255, 0) - troubled that I'm matching on a string like this.
    $('a', win).each(function (i) {
        var visited = getStyle(this, 'color', win);
        visitedList[i] = !!(visited == 'rgb(0, 255, 0)' || visited == '#0f0');
    });
    
    $(iframe).remove();
    
    filter = function (i) {
        return visitedList[i];
    };

    return $.isFunction(fn) ? this.filter(filter).each(fn) : this.filter(filter);
};

// @private

function getStyle(x,styleProp, win) {
    var x, y;
    if (x.currentStyle)
        y = x.currentStyle[styleProp];
    else if (win.defaultView.getComputedStyle) {
        y = win.defaultView.getComputedStyle(x,null).getPropertyValue(styleProp);
    }
        
    return y;
}

function iframeHeader() {
    return [
        '<!' + 'DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"', 
        '    "http://www.w3.org/TR/html4/loose.dtd">', 
        '<' + 'html>', 
        '<' + 'head>', 
        '<' + 'title>',
        ':visited iframe',
        '<' + '/title>',
        '<' + 'style>', 
        'a:visited { color: #0f0 ! important }',  // where the magic happens
        '<' + '/style>', 
        '<' + '/head>', 
        '<' + 'body>'
    ].join("\n");
}

function iframeFooter() {
    return '<' + '/body>' + '<' + '/html>';
}
    
})(jQuery);