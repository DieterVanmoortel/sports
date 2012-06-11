<?php

function sports_stopwatch_form(){
  drupal_add_css(drupal_get_path('module', 'sports') . '/stopwatch.css');
  drupal_add_js(drupal_get_path('module', 'sports') . '/js/stopwatch.js');
  drupal_add_js(drupal_get_path('module', 'sports') . '/js/jquery.stopwatch.js');
  $settings = get_settings('stopwatch');
  $form = array();
//  $form['datatype'] = array(
//      '#type' => 'radios',
//      '#title' => t('Athletes or lanes'),
//      '#options' => array('Athletes', 'Lanes'),
//  );
  $form['settings'] = array(
      '#type' => 'fieldset',
      '#attributes' => array('class' => array('sw-settings')),
  );
  $form['settings']['distance'] = array(
    '#type' => 'radios',
    '#title' => t('Distance of measurement'),
    '#options' => drupal_map_assoc(array(25,50,100)),
    '#default_value' => $settings['distance'],
    '#attributes' => array('class' => array('split-distance')),
  );
//  $form['lanes'] = array(
//      '#title' => t('lanes'),
//      '#type' => 'radios',
//      '#options' => drupal_map_assoc(range(1, $settings['maxlanes'])),
//      '#default_value' => $settings['lanes'],
//  );
  for($i = 0; $i < count($settings['users']); $i++) {
    $form[$i] = array(
        '#type' => 'fieldset',
        '#title' => $settings['users'][$i],
      '#attributes' => array('class' => array('sw-field')),        
    );
    $form[$i]['stopwatch'] = array(
      '#markup' => '<div class="timer" index="'.$i.'" class="demo">00:00:00</div>',
    );
    $form[$i]['splittime_' .$i.'_splits'] = array(
      '#type' => 'textarea',
      '#default_value' => t('Press start'),
      '#attributes' => array('class' => array('splittime'), 'index' => $i, 'split' => 0)
    );   
    $form[$i]['split'] = array(
      '#markup' => '<div class="split form-submit" style="display:none" index="'.$i. '">' . t('Add split') . '</div>',
    );
    $form[$i]['start'] = array(
      '#markup' => '<div class="form-submit start_timer" index='.$i.'><span class="triggervalue"  index="'.$i.'">'. t('Start') . '</span><span class="triggervalue" index="'.$i.'" style="display:none">' . t('Stop') . '</span></div>',
    );
  }
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

function sports_stopwatch_form_submit($form, $form_state) {
  dpm($form_state['values']);
}

/**
 * Helper function that returns settings 
 */
function get_settings($type) {
  $settings = array();
  switch($type) {
    case 'stopwatch':
      $settings['users'] = array('Jack', 'Jill', 'Dieter', 'Bientje', 'Melanie', 'Elien');
      $settings['lanes'] = array(1,2,3,4,5,6);
      $settings['maxlanes'] = 1;
      $settings['distance'] = 50;
      break; 
  }
  return $settings;
}