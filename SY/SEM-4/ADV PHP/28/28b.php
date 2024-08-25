<?php

/**
 * Implements hook_block_info().
 */
function college_block_block_info() {
  $blocks['college_announcement'] = array(
    'info' => t('CollegeSite™ Announcement'),
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function college_block_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'college_announcement':
      $block['subject'] = t('CollegeSite™');
      $block['content'] = '<p>Upcoming Event: Join us for the Annual College Fair on August 30th!</p>';
      break;
  }

  return $block;
}

/**
 * Implements hook_block_view_alter().
 */
function college_block_block_view_alter(&$data, $block) {
  if ($block->delta == 'college_announcement') {
    // Add CSS class for left-side placement if needed
    $data['content'] = '<div class="left-side-block">' . $data['content'] . '</div>';
  }
}
