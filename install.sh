#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[1;37m'

# Go to docroot/
DIR="`pwd`"
if [ -d "$DIR/docroot" ]; then
  cd docroot/
fi

env="prod"
if [ ! -z "$1" ]; then
  env=$1
fi

db_en=`drush --exact --format=string vget environment`
if [ "$db_en" == 'prod' ]; then
  echo -e "${RED}Refusing to drop production db, aborting ...${WHITE}\n";
  exit -1
fi

echo "Dropping all tables in database..."
drush sql-drop -y
echo

echo "Getting '$env' environment database..."
drush sql-sync "@$env" @self -y

echo "Configuring local development settings..."
drush vset -y environment dev
drush prepare-dev

echo "Getting the files from @$env..."
drush -v rsync "@$env:%files" @self:%files -y

drush cc all
echo "Done!"
