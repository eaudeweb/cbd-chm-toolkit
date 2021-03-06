# Change Log
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/)
and this project adheres to [Semantic Versioning](http://semver.org/).

## [0.1.1] - 2016-11-21
### Added
- Add new taxonomy subjects
- Add new field_subjects to document, event, news, fact, organization, project, video, link
- Add new drush command to populate the 'Subjects' taxonomy

## [0.1.0] - 2016-11-20
### Changes
- Added script to assign GEF country codes to countries
- Import the list of CHM sites from the provided Excel file
- Fix Solr server core during development and test deployments
- Applied security update to Drupal core 7.52
- Add field_linkedin_url, field_facebook_url to content type 'Organization'
- Added field_linkedin_url, field_facebook_url to content type 'Person'
- Add field_url and set label label to "Info URL" to content type 'faq'
- Add new taxonomy Source (data_source)
- Add field field_source linked to taxonomy data_source to content type 'fact'
- Rename label for field_url from 'Related website' to 'Source URL' in content type 'fact'
- Add field_organizer: Organization (unlimited) to content type 'event'
- Add field_contact_person: Person (unlimited) to content type 'event'
- Add field_source to content type 'document'
- Add field_authors linked to 'person', 'organisation' (unlimited) in content type 'document'
- Add new taxonomy chm_site_status
- Add field_chm_site_status linked to taxonomy chm_site_status in content type 'chm_site'
- Add field_person reference to a person in content type 'cbd-nfp'
- Add field_government to: news, organization, project, document, event, video, cbd_national_target, chm_site
- Remove field_countries from: cbd_national_target, chm_site and change migration, views to use the new field
- Add new taxonomy cbd_country_group
- Add new taxonomy un_region
- Add new field field_un_region to taxonomy 'countries'
- Add new field field_parent_country to taxonomy 'countries'
- Add field_organizers and field_contact_persons to content type 'event'
- Migrate from NBSAPs into the document content type
- Improved block performance by caching the content (statistics block, footer blocks)
- Added footer menu to Bioland, Albania and Kazakhstan portals
