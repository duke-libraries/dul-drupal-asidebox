<?php

function asidebox_admin_settings_form() {
	$form = array();
	
	$types = node_type_get_types();
	foreach ($types as $node_type) {
		$options[$node_type->type] = $node_type->name;
	}
	$form['asidebox_node_types'] = array(
		'#type' => 'checkboxes',
		'#title' => t('Expose <strong>Aside (Feature) Boxes</strong> for these content types.'),
		'#options' => $options,
		'#default_value' => variable_get('asidebox_node_types', array('page')),
		'#description' => t('Content authors will be able to add <em>Aside Box</em> for these content types.'),
	);
	$form['actions'] = array('#type' => 'actions');
	$form['actions']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save'),
	);
	return $form;
}

function asidebox_admin_settings_form_submit($form, $form_state) {
	$options = array();
	foreach ($form_state['values']['asidebox_node_types'] as $key => $value) {
		if ($value) {
			$options[] = $key;
		}
	}
	variable_set('asidebox_node_types', $options);
	drupal_set_message(t('Your changes have been saved.'));
}
	