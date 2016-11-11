<?php

class CHMPortalEventsMigrationTest extends CHMPortalMigrationTestBase {


  function getNodeId() {
    return db_select('migrate_map_demo_events')
      ->fields(NULL, array('destid1'))
      ->condition('sourceid1', 'events/celebrarea-zilei-internationale-biodiversitatii')
      ->execute()->fetchField();
  }


  public function test() {
    $nid = $this->getNodeId();
    // var_dump($nid);
    $this->assertNotEmpty($nid);
    $node = node_load($nid);
    $this->assertNotNull($node);

    /** @var stdClass $w */
    $w = entity_metadata_wrapper('node', $nid);
    $this->assertEquals("1273491756", $w->created->value());
    $this->assertEquals("1321634860", $w->changed->value());
    $this->assertEquals("1", $w->status->value());
    $this->assertEquals("1", $node->sticky);
    $this->assertEquals(6, count($w->field_keywords->value()));
    // var_dump($w->field_countries->value());
    $this->assertEquals("The sample biodiversity" , $w->label());
    $this->assertEquals(2, count($node->title_field));
    $this->assertEquals(2, count($node->body));
    $this->assertEquals('<p><a href="#">description english</a></p>', $node->body['en'][0]['value']);
    $this->assertEquals('<p><a href="#">description french</a></p>', $node->body['fr'][0]['value']);
    $this->assertEquals('2010-05-19 13:15:43', $w->field_dates->value()['value']);
    $this->assertEquals('2010-05-20 17:43:21', $w->field_dates->value()['value2']);
    $this->assertEquals('2010-05-20 17:43:21', $w->field_dates->value()['value2']);
    $this->assertEquals('http://www.google.ro/event.xml', $w->field_url->value()['url']);
    var_dump($node->field_event_address);

    return $this->getFailuresCount() == 0;
  }
}
