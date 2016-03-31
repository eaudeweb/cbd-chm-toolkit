<?php

/**
 * @file
 * Contains Drupal\chm_news\Tests\CBDNewsTest.
 *
 * Test cases for testing the chm_news module.
 */

namespace Drupal\chm_news\Tests;

use Drupal\simpletest\WebTestBase;
use Drupal\node\Entity\NodeType;
use Drupal\node\NodeTypeInterface;

/**
 * Test that our content types are successfully created.
 *
 * @ingroup chm
 * @group chm
 */
class NewsTest extends WebTestBase {

  /**
   * Modules to enable.
   *
   * @var array
   */
  public static $modules = array('node', 'chm_news');

  /**
   * The installation profile to use with this test.
   *
   * We need the 'minimal' profile in order to make sure the Tool block is
   * available.
   *
   * @var string
   */
  protected $profile = 'standard';

  /**
   * Data provider for testing menu links.
   *
   * @return array
   *   Array of page -> link relationships to check for.
   *   - The key is the path to the page where our link should appear.
   *   - The value is the link that should appear on that page.
   */
  protected function providerMenuLinks() {
    return array(
      '' => '/system/cbd/news',
    );
  }

  /**
   * Verify and validate that default menu links were loaded for this module.
   */
  public function testNewsItem() {
    // Test that our page loads.
    $this->drupalGet('/system/cbd/news');
    $this->assertResponse(200, 'Description page exists.');

    // Test that our menu links were created.
    $links = $this->providerMenuLinks();
    foreach ($links as $page => $path) {
      $this->drupalGet($page);
      $this->assertLinkByHref($path);
    }
  }

  /**
   * Test our new content types.
   *
   * Tests for the following:
   *
   * - That our content types appear in the user interface.
   * - That our unlocked content type is unlocked.
   * - That our locked content type is locked.
   * - That we can create content using the user interface.
   * - That our created content does appear in the database.
   */
  public function testNodeType() {
    // Log in an admin user.
    $admin_user = $this->drupalCreateUser(array('administer content types'));
    $this->drupalLogin($admin_user);

    // Get a list of content types.
    $this->drupalGet('/admin/structure/types');
    $this->assertRaw('Content type to add news in the website', 'News item content type found.');

    // Check for the locked status of our content types.
    /** @var NodeTypeInterface $node_type */
    $node_type = NodeType::load('news');
    $this->assertTrue($node_type, 'news exists.');
    if ($node_type) {
      $this->assertTrue($node_type->isLocked(), 'news is not locked.');
    }

    // Log in a content creator.
    $creator_user = $this->drupalCreateUser(array('create news content'));
    $this->drupalLogin($creator_user);

    // Create a node.
    $edit = array();
    $edit['title[0][value]'] = $this->randomMachineName(8);
    $edit['body[0][value]'] = $this->randomMachineName(16);
    $this->drupalPostForm('/node/add/news', $edit, t('Save'));

    // Check that the Basic page has been created.
    $this->assertText(t('@post @title has been created.', array(
      '@post' => 'News',
      '@title' => $edit['title[0][value]'],
    )), 'News item created.');

    // Check that the node exists in the database.
    $node = $this->drupalGetNodeByTitle($edit['title[0][value]']);
    $this->assertTrue($node, 'Node found in database.');
  }
}
