Taxonomy Node
----------------------
Author - Ariel Barreiro (hanoii) http://drupal.org/user/23157
abarrei@gmail.com

Overview:
--------
It creates a single node of a configurable content type for each term in a
specific vocabulary.

In this way you can extend the term to hold any other information that a node
(cck preferably) can hold. It's an useful module to create different category
listings using views. This module prevent you to edit or delete the created
node, handles updates and deletion of terms.

It also handles hierarchy by automatically assigning the vocabulary to the set
content type and maintaining the hierarchy on the node as well.

It would be the opposite of the Node Auto Term [NAT] module.

Sponsored by:
Infomagnet (http://www.infomagnet.com)

Installation:
------------

1. Copy the taxonomynode directory to the Drupal sites/<...>/modules/ directory.

2. Go to "Administer" -> "Modules" and enable the module.

3. Go to "Administer" -> "Categories" and edit the vocabulary you want to
associate with a specific content type.

4. (Optional) Use the batch creation checkbox to create nodes for the terms
already there before installing this module. There's a limit of 50 nodes in this
batch processing so you'll have to do that several times if you have a lot of
terms.

5. Now, when you edit an already created term, you'll find a link to the
associated node to edit the node as well. You won't be able to edit the title or
delete the node from the node edition page, you must do so from the term edit
page.

6. (Optional) Go To "Aminister" -> "Settings" -> "Taxonomy Node" and choose
if you want node operations to sync to specific terms.

Last updated:
------------
$Id: README.txt,v 1.2 2009/05/28 19:38:22 hanoii Exp $