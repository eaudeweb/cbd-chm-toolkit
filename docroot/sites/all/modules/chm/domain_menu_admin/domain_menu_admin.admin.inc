<?php

function domain_menu_admin_overview_page() {
  $result = db_query("SELECT * FROM {menu_custom} ORDER BY title", array(), array('fetch' => PDO::FETCH_ASSOC));
  $header = array(t('Title'), array('data' => t('Operations'), 'colspan' => '3'));
  $rows = array();
  foreach ($result as $menu) {

    $row = array(theme('menu_admin_overview', array('title' => $menu['title'], 'name' => $menu['menu_name'], 'description' => $menu['description'])));
    $row[] = array('data' => l(t('list links'), 'admin/structure/menu/manage/' . $menu['menu_name']));
    $row[] = array('data' => l(t('edit menu'), 'admin/structure/menu/manage/' . $menu['menu_name'] . '/edit'));
    $row[] = array('data' => l(t('add link'), 'admin/structure/menu/manage/' . $menu['menu_name'] . '/add'));
    $rows[] = $row;
  }

  return theme('table', array('header' => $header, 'rows' => $rows));

}