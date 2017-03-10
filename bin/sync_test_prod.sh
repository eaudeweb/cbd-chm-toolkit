#!/bin/bash

# Put production environment to the test environment

RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[1;37m'

echo -e "${GREEN}      _               _              _ _    _ _   "
echo -e " THE | | CBD         | |            | | |  (_) |  "
echo -e "  ___| |__  _ __ ___ | |_ ___   ___ | | | ___| |_ "
echo -e " / __| '_ \| '_ \` _ \| __/ _ \ / _ \| | |/ / | __|"
echo -e "| (__| | | | | | | | | || (_) | (_) | |   <| | |_ "
echo -e " \___|_| |_|_| |_| |_|\__\___/ \___/|_|_|\_\_|\__|"
echo -e "                        kool stuff is happenning..."
echo -e ""

# Avoid dropping non-local environments
db_en=`drush --exact --format=string vget environment`
if [ "$?" == 0 ] && [ "$db_en" != 'test' ]; then
  echo -e "${RED}ERROR: Refusing to destroy the current environment ($env). Please set environment to 'test' (drush vset environment test)\n";
  exit -1
fi

cd ../docroot/
drush sql-drop -y
drush sql-sync @prod @self -y
drush vset environment test
drush prepare-test -y
drush cc all

echo -e "${GREEN}Sync done, to get the files do: drush rsync @prod:%files @self:%files -y";
