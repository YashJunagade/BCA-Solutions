<?php

use Drupal\node\Entity\Node;
use Drupal\taxonomy\Entity\Term;
use Drupal\menu_link_content\Entity\MenuLinkContent;
use Drupal\Core\Link;
use Drupal\Core\Url;
use Drupal\Core\StringTranslation\StringTranslationTrait;

/**
 * Implements hook_install().
 */
function custom_about_me_install() {
  // Create a Basic Page node
  $node = Node::create([
    'type' => 'page',
    'title' => 'About Me',
    'body' => [
      'value' => 'This is the page where you add details about yourself.',
      'format' => 'basic_html',
    ],
    'status' => 1,
  ]);
  $node->save();
  
  // Add the node to the main menu
  $menu_link = MenuLinkContent::create([
    'menu_name' => 'main-menu',
    'link_path' => 'node/' . $node->id(),
    'title' => 'About Me',
    'options' => [
      'attributes' => [
        'title' => 'This is ' . 'Your Name',
      ],
    ],
    'weight' => -10,
  ]);
  $menu_link->save();
}
