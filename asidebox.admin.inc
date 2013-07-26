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
	$form['revision_options'] = array(
		'#type' => 'fieldset',
		'#title' => t('Content Revision Options'),
	);
	$form['menu_help_text'] = array(
		'#type' => 'textarea',
		'#cols' => 20,
		'#rows' => 5,
		'#title' => t("Help text to display under the <em><strong>Aside Box Status</strong></em> menu"),
		'#default_value' => variable_get('asidebox.menu_help', t('Disable the aside box, or specify the type of content.')),
	);
	$form['revision_options']['follow_revisions'] = array(
		'#type' => 'checkbox',
		'#title' => t('Asidebox content follows content revisions?'),
		'#default_value' => variable_get('asidebox.follow_new_revisions', 0),
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
	variable_set('asidebox.follow_new_revisions', $form_state['values']['follow_revisions']);
	variable_set('asidebox.menu_help', $form_state['values']['menu_help_text']);
	#error_log('follow_revisions = [' . $form_state['values']['follow_revisions'] . ']');
	drupal_set_message(t('Your changes have been saved.'));
}
	
