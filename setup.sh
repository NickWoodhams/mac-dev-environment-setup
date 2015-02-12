#! /bin/bash
# Setup script

ln -s /Applications ~/Applications
cp -R "Sublime Text.app" ~/Applications/
ln -s "/Applications/Sublime Text.app/Contents/SharedSupport/bin/subl" /usr/local/bin/subl
subl test.txt
cat Sublime-Support.tar.part.* > Sublime-Support.tar
mv Sublime-Support.tar "~/Library/Application Support/"
cd "~/Library/Application Support/"
tar -xvf Sublime-Support.tar
rm Sublime-Support.tar
cp -R "GitHub.app" ~/Applications/
cp -R "iTerm.app" ~/Applications/
cp com.googlecode.iterm2.plist ~/Library/Preferences/
open "Iterm.app"
cp -R "Postgres.app" ~/Applications/
curl -L http://install.ohmyz.sh | sh
open ~/Applications/iTerm.app
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
brew doctor
brew update
brew install wget
brew install imagemagick
brew install python
brew install node
npm install -g less
npm install -g jslint
npm install -g jshint
npm install -g bower
pip install —upgrade setuptools
pip install virtualenv
pip install virtualenvwrapper
cat virtualenvwrapper-appendtext.txt >> ~/.zshrc
mkvirtualenv venv
brew install libtiff libjpeg webp little-cms2
pip install Pillow
pip install reportlab
pip install django
pip install flask
pip install requests
brew install mysql
unset TMPDIR
mysql_install_db --verbose --user=`whoami` --basedir="$(brew --prefix mysql)" --datadir=/usr/local/var/mysql --tmpdir=/tmp
mysql.server start
mysql_secure_installation
