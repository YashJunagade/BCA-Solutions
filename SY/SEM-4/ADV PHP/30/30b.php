<?php

// contact_details.info.yml
$info_yml = <<<YAML
name: 'Contact Details'
type: module
description: 'Displays contact details and adds a navigation link.'
core_version_requirement: ^8 || ^9
package: Custom
dependencies:
  - drupal:menu_link_content
YAML;
file_put_contents('modules/custom/contact_details/contact_details.info.yml', $info_yml);

// contact_details.routing.yml
$routing_yml = <<<YAML
contact_details.page:
  path: '/contact-details'
  defaults:
    _controller: '\Drupal\contact_details\Controller\ContactDetailsController::content'
    _title: 'Contact Details'
  requirements:
    _permission: 'access content'
YAML;
file_put_contents('modules/custom/contact_details/contact_details.routing.yml', $routing_yml);

// src/Controller/ContactDetailsController.php
$controller_php = <<<PHP
<?php

namespace Drupal\contact_details\Controller;

use Drupal\Core\Controller\ControllerBase;

/**
 * Class ContactDetailsController.
 */
class ContactDetailsController extends ControllerBase {

  /**
   * Returns the content for the contact details page.
   */
  public function content() {
    return [
      '#type' => 'markup',
      '#markup' => '<h1>Contact Details</h1>
                    <p>Name: John Doe</p>
                    <p>Roll No: 12345</p>
                    <p>Address: 123 Main Street, Anytown</p>
                    <p>Phone: (555) 123-4567</p>',
    ];
  }

}
PHP;
file_put_contents('modules/custom/contact_details/src/Controller/ContactDetailsController.php', $controller_php);

// contact_details.module
$module_php = <<<PHP
<?php

/**
 * Implements hook_menu().
 */
function contact_details_menu() {
  $items = [];

  $items['contact-details'] = [
    'title' => 'Contact Details',
    'page callback' => 'contact_details_page',
    'access callback' => TRUE,
    'type' => MENU_CALLBACK,
  ];

  return $items;
}

/**
 * Page callback for contact-details.
 */
function contact_details_page() {
  return '<h1>Contact Details</h1>
          <p>Name: John Doe</p>
          <p>Roll No: 12345</p>
          <p>Address: 123 Main Street, Anytown</p>
          <p>Phone: (555) 123-4567</p>';
}
PHP;
file_put_contents('modules/custom/contact_details/contact_details.module', $module_php);

echo "Drupal module created successfully.\n";
