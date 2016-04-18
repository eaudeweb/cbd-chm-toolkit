<?php

/**
 * @file
 * Contains Drupal\chm_news\Tests\CBDNewsTest.
 *
 * Test cases for testing the chm_news module.
 */

namespace Drupal\country_taxonomy\Tests;

use Drupal\simpletest\WebTestBase;
use Drupal\node\Entity\NodeType;
use Drupal\node\NodeTypeInterface;

/**
 * Test that our content types are successfully created.
 *
 * @ingroup country_taxonomy
 * @group country_taxonomy
 */
class CountryTaxonomyTest extends WebTestBase {

  /**
   * Modules to enable.
   *
   * @var array
   */
  public static $modules = array('field_ui', 'country_taxonomy');

  public function testTaxonomyCreation() {
    // Log in an admin user.
    $admin_user = $this->drupalCreateUser(array(
      'administer taxonomy' , 'administer taxonomy_term fields'
    ));
    $this->drupalLogin($admin_user);

    // Get a list of content types.
    $this->drupalGet('/admin/structure/taxonomy');
    $this->assertText('Country', 'Country taxonomy found');
    $this->assertText('Region', 'Region taxonomy found');

    $this->drupalGet('/admin/structure/taxonomy/manage/country/overview/fields');
    $this->assertText('field_country_eu', 'Field field_country_eu found');
    $this->assertText('field_country_flag', 'Field field_country_flag found');
    $this->assertText('field_country_iso2', 'Field field_country_iso2 found');
    $this->assertText('field_country_iso3', 'Field field_country_iso3 found');
    $this->assertText('field_country_official_name', 'Field field_country_official_name found');
    $this->assertText('field_region', 'Field field_region found');

    $this->drupalGet('/admin/structure/taxonomy/manage/region/overview/fields');
  }
}
