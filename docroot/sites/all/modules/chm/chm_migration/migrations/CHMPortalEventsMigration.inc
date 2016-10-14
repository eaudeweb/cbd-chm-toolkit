<?php

class CHMPortalEventsMigration extends CHMPortalBaseMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'url' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Entity original ID',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );
    $this->source = new CHMEventsNestedDirJSONSource($arguments);
    $this->destination = new MigrateDestinationNode('event');

    $this->addFieldMapping('title', 'title_en');
    $this->addFieldMapping('field_email', 'email');
    $this->addFieldMapping('language')->defaultValue('en');

    $this->addFieldMapping('domain_site')->defaultValue(FALSE);
    $this->addFieldMapping('domain_source', 'domain_source');
    $this->addFieldMapping('domains', 'domains');
    $this->addFieldMapping('uid')->defaultValue(USER_WALLE);
  }

  /**
   * {@inheritdoc}
   */
  function prepareRowObject($row) {
    // TODO: Implement prepareRowObject() method.
  }

  /**
   * {@inheritdoc}
   */
  function validateRowObject($row) {
    // TODO: Implement validateRowObject() method.
  }
}
