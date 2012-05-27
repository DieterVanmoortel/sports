<?php

function sports_load_form(){
  $form = array();
  $types = array('plus', 'minus');
  for ($i=1; $i<6; $i++){
    $form[$i] = array(
        '#type' => 'fieldset',
    );
    $form[$i]['value'] = array(
        '#type' => 'button',
        '#value' => $i,
        '#disabled' => TRUE,
    );
    foreach($types as $type) {
      $form[$i][$type] =  array(
          '#type' => 'button',
          '#value' => $type,
      );
    }
          $form[$i]['total'] =  array(
          '#type' => 'textfield',
          '#default_value' => '0',
      );
  }
  return system_settings_form($form);
}


function sports_stopwatch_form(){
  $form = array();
  return $form;
}