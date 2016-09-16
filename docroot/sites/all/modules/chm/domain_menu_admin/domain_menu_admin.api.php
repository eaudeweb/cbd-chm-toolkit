<?php


/**
 * Hook to determine if the current user is administrator. This is used to allow
 * administrators to view all the menu items.
 *
 * @param boolean $is_administrator
 *   Specify if the current user has administrative privileges
 */
function hook_user_is_administrator_alter(&$is_administrator) {
  global $user;
  $is_administrator = in_array('administrator', $user->roles);
}
