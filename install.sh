#!/bin/bash
# Go to docroot/

DIR="`pwd`"
if [ -d "$DIR/docroot" ]; then
  cd docroot/
fi

env="prod"
if [ ! -z "$1" ]; then
  env=$1
fi

echo "Dropping all tables in database..."
drush sql-drop -y
echo

echo "Getting '$env' environment database..."
drush sql-sync "@$env" @self -y

echo "Getting the files from @$env..."
drush -v rsync "@$env:%files" @self:%files -y

echo "Configuring local development settings..."
drush vset environment dev
drush prepare-dev
# Enable modules
# drush en -y devel simpletest

drush cc all
echo "Done!"
