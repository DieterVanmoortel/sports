<?php
function sports_general_settings($plugin = NULL){
  $form = array();
  $q = db_select('users', 'u')
          ->fields('u', array('name', 'uid'))
          ->condition('status', 1)
          ->execute()
          ->fetchAllAssoc('uid');
 foreach((array)$q as $row){
   $users [$row->uid] = $row->name;
 }
dpm($users);
  $form['active_users'] = array(
      '#type' => 'checkboxes',
      '#options' => $users,
      '#title' => t('Active users'),
  );
      $settings['maxlanes'] = 1;
      $settings['distance'] = 50;
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    );
  return $form;
}

function sports_general_settings_submit($form, &$form_state){
  dpm($form_state['values']);
}