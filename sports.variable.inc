<?php

/**
 * @file
 * Definition of all custom variables
 * Variable module hook implementations
 */


/**
 * Implements hook_variable_group_info().
 */
function sports_variable_group_info() {
  $groups['sports'] = array(
    'title' => t('Sports'),
    'description' => t('Sports Administration settings.'),
    'access' => 'coach',
  );
  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function sports_variable_info($options) {
  $variables['map_entity_type'] = array(
    'title' => t('Mapped content'),
    'type' => 'options',
    'group' => 'map',
    'options callback' => 'map_view_content_types',
    'default' => array(),
  );
  
  return $variables;
}

