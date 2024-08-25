<?php
/**
 * Implements hook_menu().
 */
function my_custom_module_menu() {
  $items = array();

  // Define a menu item for creating the article.
  $items['admin/create-article'] = array(
    'title' => 'Create Article',
    'page callback' => 'my_custom_module_create_article',
    'access callback' => TRUE,
    'type' => MENU_CALLBACK,
  );

  return $items;
}

/**
 * Page callback function to create the article.
 */
function my_custom_module_create_article() {
  // Create a new node of type 'article'
  $node = new stdClass();
  $node->type = 'article';
  node_object_prepare($node);

  $node->title = 'My Article';
  $node->body['und'][0]['value'] = 'PHP is a popular general-purpose scripting language that is especially suited to web development. 
  Fast, flexible and pragmatic, PHP powers everything from your blog to the most popular websites in the world.';

  // Add an image field (assuming the field name is field_image)
  $file = file_save_data(file_get_contents('http://example.com/path/to/your/image.jpg'), 'public://image.jpg', FILE_EXISTS_REPLACE);
  $node->field_image['und'][0] = array(
    'fid' => $file->fid,
    'alt' => 'PHP Programming Language',
  );

  $node->status = 1; // Published
  $node->promote = 1; // Show on front page
  $node->sticky = 0; // Not sticky

  node_save($node);

  // Add the link to the Main Menu.
  $menu_link = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/' . $node->nid,
    'link_title' => 'My Article',
    'weight' => -10, // To make it appear before other items
    'options' => array('attributes' => array('title' => 'This is ' . 'Your Name')),
  );
  menu_link_save($menu_link);

  // Post a comment to the article.
  $comment = new stdClass();
  $comment->pid = 0;
  $comment->nid = $node->nid;
  $comment->uid = 1; // Assuming user ID 1 (admin)
  $comment->subject = 'Great Article!';
  $comment->comment_body[LANGUAGE_NONE][0]['value'] = 'This is a really informative article about PHP programming.';
  $comment->status = 1; // Published

  comment_save($comment);

  return 'Article created and added to the menu. <a href="/node/' . $node->nid . '">View Article</a>';
}
