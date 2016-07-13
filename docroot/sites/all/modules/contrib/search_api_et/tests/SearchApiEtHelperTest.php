<?php

/**
 * @file
 * Helper class for SearchAPI ET
 */
class SearchApiEtHelperTest extends PHPUnit_Framework_TestCase {

  /**
   * @return array
   */
  public function dataProviderIsValidItemId() {
    return array(
      'test empty' => array(false, ''),
      'test null' => array(false, ''),
      'test back-slash' => array(false, '\\'),
      'test back-slash length' => array(false, '1\\b'),
      'test 1/' => array(false, '1/'),
      'test 1/a' => array(true, '1/a'),
      'test 1/en' => array(true, '1/en'),
    );
  }

  /**
   * @dataProvider dataProviderIsValidItemId
   * @param $expected
   * @param $value
   */
  public function testIsValidItemId($expected, $value) {
    $this->assertEquals($expected, SearchApiEtHelper::isValidItemId($value));
  }

  /**
   * @return array
   */
  function dataProviderSplitItemId() {
    return array(
      'entity_id' => array('123', '123/en', SearchApiEtHelper::ITEM_ID_ENTITY_ID),
      'language' => array('en', '123/en', SearchApiEtHelper::ITEM_ID_LANGUAGE),
      'split' => array(array(
          SearchApiEtHelper::ITEM_ID_ENTITY_ID => 123,
          SearchApiEtHelper::ITEM_ID_LANGUAGE => 'en'
        ),
        '123/en'),
      'wrong part 1' => array(null, '123/en', 'wrong-part'),
    );
  }

  /**
   * @dataProvider dataProviderSplitItemId
   * @param $expected
   * @param $value
   * @param $parts
   */
  public function testSplitItemId($expected, $value, $parts = NULL) {
    $this->assertEquals($expected, SearchApiEtHelper::splitItemId($value, $parts));
  }
}
