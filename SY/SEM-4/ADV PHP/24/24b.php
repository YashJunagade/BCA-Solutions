<!-- department.php  -->

<?php

/**
 * Implements hook_menu().
 */
function department_portal_menu() {
  $items = array();

  // Define a page for DepartmentPortal
  $items['department-portal'] = array(
    'title' => 'Department Portal',
    'page callback' => 'department_portal_page',
    'access callback' => TRUE,
    'type' => MENU_CALLBACK,
  );

  return $items;
}

/**
 * Page callback function to display the content.
 */
function department_portal_page() {
  $content = '<h2>Departments</h2>';
  $content .= '<ul>';
  $content .= '<li>Computer Science</li>';
  $content .= '<li>Mathematics</li>';
  $content .= '<li>Physics</li>';
  $content .= '<li>Chemistry</li>';
  $content .= '</ul>';
  $content .= '<h2>Teacher Details</h2>';
  $content .= '<ul>';
  $content .= '<li><strong>Dr. Alice Smith</strong> - Head of Computer Science Department</li>';
  $content .= '<li><strong>Prof. John Doe</strong> - Mathematics Department</li>';
  $content .= '<li><strong>Dr. Jane Johnson</strong> - Physics Department</li>';
  $content .= '<li><strong>Prof. Emily Davis</strong> - Chemistry Department</li>';
  $content .= '</ul>';

  return $content;
}

/**
 * Implements hook_menu_alter().
 */
function department_portal_menu_alter(&$items) {
  // Add the page link to the Main Menu.
  $items['department-portal']['menu_name'] = 'main-menu';
  $items['department-portal']['weight'] = -10; // To make it appear at the top
}
