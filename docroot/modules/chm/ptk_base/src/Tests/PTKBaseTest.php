<?php

/**
 * @file
 * Contains Drupal\ptk_base\Tests\PTKBaseTest.
 *
 * Part of the ptk_base module test cases.
 */

namespace Drupal\ptk_base\Tests;

use Drupal\simpletest\WebTestBase;

/**
 * Test that our structures are successfully created.
 *
 * @ingroup ptk_base
 * @group ptk_base
 */
class PTKBaseTest extends WebTestBase {

  /**
   * Modules to enable.
   *
   * @var array
   */
  public static $modules = array('field_ui', 'ptk_base');

  function setUp() {
    parent::setUp();
    // Log in an admin user.
    $admin_user = $this->drupalCreateUser(array(
      'administer taxonomy' , 'administer taxonomy_term fields'
    ));
    $this->drupalLogin($admin_user);
  }

  public function testTaxonomyCreation() {
    $this->drupalGet('/admin/structure/taxonomy');
    $this->assertText('Aichi biodiversity target', 'Aichi biodiversity target taxonomy found');
  }

  public function testTaxonomyTermData() {
    $this->drupalGet('/admin/structure/taxonomy/manage/aichi_target/overview');
    $this->assertText('Aichi Strategic Goal A');
    $this->assertText('Aichi Strategic Goal B');
    $this->assertText('Aichi Strategic Goal C');
    $this->assertText('Aichi Strategic Goal D');
    $this->assertText('Aichi Strategic Goal E');

    foreach(range(1, 20) as $k) {
      $this->assertText('Aichi Target ' . $k);
    }
  }
}
