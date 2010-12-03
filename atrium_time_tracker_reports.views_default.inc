<?php

/**
 * Implementation of hook_views_default_views().
 */
function atrium_time_tracker_reports_views_default_views() {
  $views = array();

  // Exported view: atrium_time_tracker_reports
  $view = new view;
  $view->name = 'atrium_time_tracker_reports';
  $view->description = 'A view for reporting on time tracker data, specifically in Open Atrium.';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'time_tracker_entry';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'uid' => array(
      'label' => 'User',
      'required' => 0,
      'id' => 'uid',
      'table' => 'time_tracker_entry',
      'field' => 'uid',
      'relationship' => 'none',
    ),
    'cid' => array(
      'label' => 'Comment',
      'required' => 0,
      'id' => 'cid',
      'table' => 'time_tracker_entry',
      'field' => 'cid',
      'relationship' => 'none',
    ),
    'nid' => array(
      'label' => 'Node',
      'required' => 0,
      'id' => 'nid',
      'table' => 'time_tracker_entry',
      'field' => 'nid',
      'relationship' => 'none',
    ),
    'pid' => array(
      'label' => 'project',
      'required' => 0,
      'id' => 'pid',
      'table' => 'casetracker_case',
      'field' => 'pid',
      'relationship' => 'nid',
    ),
    'group_nid' => array(
      'label' => 'Group node',
      'required' => 0,
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'relationship' => 'nid',
    ),
    'activity' => array(
      'label' => 'Activity',
      'required' => 0,
      'id' => 'activity',
      'table' => 'time_tracker_entry',
      'field' => 'activity',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'name' => array(
      'label' => 'Name / Group',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'overwrite_anonymous' => 0,
      'anonymous_text' => '',
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'uid',
    ),
    'title_2' => array(
      'label' => 'Group',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'spaces' => array(
        'frontpage' => 1,
        'type' => 'spaces_og',
      ),
      'exclude' => 0,
      'id' => 'title_2',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'group_nid',
    ),
    'title_1' => array(
      'label' => 'Project',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title_1',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'pid',
    ),
    'title' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'nid',
    ),
    'comment' => array(
      'label' => 'Body',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '200',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'comment',
      'table' => 'comments',
      'field' => 'comment',
      'relationship' => 'cid',
    ),
    'timestamp' => array(
      'label' => 'Timestamp',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'custom',
      'custom_date_format' => 'M jS, Y',
      'reldate' => '0',
      'exclude' => 0,
      'id' => 'timestamp',
      'table' => 'time_tracker_entry',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
    'duration' => array(
      'label' => 'Duration',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => ' hours',
      'exclude' => 0,
      'id' => 'duration',
      'table' => 'time_tracker_entry',
      'field' => 'duration',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'timestamp' => array(
      'id' => 'timestamp',
      'table' => 'time_tracker_entry',
      'field' => 'timestamp',
    ),
  ));
  $handler->override_option('arguments', array(
    'name' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'glossary' => 0,
      'limit' => '0',
      'case' => 'none',
      'path_case' => 'none',
      'transform_dash' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'uid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
        '5' => 0,
        '4' => 0,
      ),
      'default_options_div_prefix' => '',
      'default_argument_fixed' => 'Chris Eastwood',
      'default_argument_user' => 0,
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'book' => 0,
        'event' => 0,
        'feed_ical' => 0,
        'feed_ical_item' => 0,
        'group' => 0,
        'profile' => 0,
        'shoutbox' => 0,
        'casetracker_basic_case' => 0,
        'casetracker_basic_project' => 0,
        'feed' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_is_member' => 'OG_VIEWS_DO_NOT_VALIDATE_MEMBERSHIP',
      'validate_argument_group_node_type' => array(
        'group' => 0,
      ),
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'uid' => array(
      'operator' => 'in',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'uid_op',
        'identifier' => 'uid',
        'label' => 'Name',
        'optional' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'uid',
      'table' => 'users',
      'field' => 'uid',
      'relationship' => 'uid',
    ),
    'timestamp' => array(
      'operator' => 'between',
      'value' => array(
        'type' => 'relative',
        'value' => '',
        'min' => 'bimonthly',
        'max' => 'bimonthly',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'timestamp_op',
        'identifier' => 'timestamp',
        'label' => 'Entered Between',
        'optional' => 1,
        'remember' => 0,
      ),
      'id' => 'timestamp',
      'table' => 'time_tracker_entry',
      'field' => 'timestamp',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'group_nid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'group_nid_op',
        'identifier' => 'group_nid',
        'label' => 'Groups',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'relationship' => 'nid',
      'reduce_duplicates' => 0,
    ),
    'pid' => array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'pid_op',
        'identifier' => 'pid',
        'label' => 'Project',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
      ),
      'id' => 'pid',
      'table' => 'casetracker_case',
      'field' => 'pid',
      'relationship' => 'nid',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      '4' => 4,
    ),
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'views_calc');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'name' => 'name',
      'title_2' => 'name',
      'title_1' => 'title_1',
      'title' => 'title',
      'comment' => 'comment',
      'timestamp' => 'timestamp',
      'duration' => 'duration',
    ),
    'info' => array(
      'name' => array(
        'sortable' => 0,
        'separator' => '<br/>',
        'justification' => 'views_calc_justify_none',
        'has_calc' => 0,
        'calc' => array(),
      ),
      'title_2' => array(
        'sortable' => 0,
        'separator' => '<br/>',
        'justification' => 'views_calc_justify_none',
        'has_calc' => 0,
        'calc' => array(),
      ),
      'title_1' => array(
        'sortable' => 0,
        'separator' => '',
        'justification' => 'views_calc_justify_none',
        'has_calc' => 0,
        'calc' => array(),
      ),
      'title' => array(
        'sortable' => 0,
        'separator' => '',
        'justification' => 'views_calc_justify_none',
        'has_calc' => 0,
        'calc' => array(),
      ),
      'comment' => array(
        'separator' => '',
        'justification' => 'views_calc_justify_none',
        'has_calc' => 0,
        'calc' => array(),
      ),
      'timestamp' => array(
        'separator' => '',
        'justification' => 'views_calc_justify_none',
        'has_calc' => 0,
        'calc' => array(),
      ),
      'duration' => array(
        'separator' => '',
        'justification' => 'views_calc_justify_none',
        'has_calc' => 1,
        'calc' => array(
          'SUM' => 'SUM',
        ),
      ),
    ),
    'default' => '-1',
    'detailed_values' => '0',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('arguments', array());
  $handler->override_option('path', 'time_tracker/atrium_reports');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => 'Reports',
    'description' => '',
    'weight' => '0',
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $translatables['atrium_time_tracker_reports'] = array(
    t('Defaults'),
    t('Page'),
  );

  $views[$view->name] = $view;

  return $views;
}