<?php

class CHMServerConsumerNFPMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Entity original ID',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );
    $this->source = new CHMServerConsumerNFPMigrateSource($arguments['urlPattern']);
    $this->destination = new MigrateDestinationNode('cbd_nfp');

    $this->addFieldMapping('field_url', 'website');
    $this->addFieldMapping('field_email', 'email');
    $this->addFieldMapping('field_alternative_emails', 'emailAlts');
    $this->addFieldMapping('field_fax_numbers', 'faxes');
    $this->addFieldMapping('field_phone_numbers', 'phones');
    $this->addFieldMapping('field_country', 'country');
    $this->addFieldMapping('field_postal_code', 'postalCode');
    $this->addFieldMapping('field_state', 'state');
    $this->addFieldMapping('field_city', 'city');
    $this->addFieldMapping('field_address', 'address');
    $this->addFieldMapping('field_organization_name', 'organization');
    $this->addFieldMapping('field_organization_acronym', 'organizationAcronym');
    $this->addFieldMapping('field_department', 'department');
    $this->addFieldMapping('field_nfp_designation', 'designation');
    $this->addFieldMapping('field_first_name', 'firstName');
    $this->addFieldMapping('field_last_name', 'lastName');
    $this->addFieldMapping('field_salutation', 'salutation');
    $this->addFieldMapping('field_nfp_type', 'types');
  }
}


class CHMServerConsumerNFPMigrateSource extends CHMServerConsumerMigrateSource {

  /**
   * @inheritdoc
   */
  public function fields() {
    return [
      '_id'                 => 'Remote record ID',
      'website'             => 'Website',
      'emailAlts'           => 'Alternative e-mails',
      "email"               => 'Email',
      "faxes"               => 'One or more fax numbers',
      "phones"              => 'One or more phone numbers',
      "country"             => 'Country',
      "postalCode"          => 'Postal code',
      "state"               => 'State',
      "city"                => 'City',
      "address"             => 'Address',
      "organizationAcronym" => 'Organisation acronym',
      "organization"        => 'Organisation name',
      "department"          => 'Department',
      "designation"         => 'Designation',
      "lastName"            => 'Last name',
      "firstName"           => 'First name',
      "salutation"          => 'Salutation',
      "types"               => 'Focal point roles',
      "government"          => 'Government ISO code',
      "__v"                 => 'Version',
    ];
  }
}
