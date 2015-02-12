## Dev Setup Instructions

####Download/Install XCode
<https://itunes.apple.com/us/app/xcode/id497799835?mt=12>

After it is done installing, run:

    sudo xcodebuild -license

Press the spacebar until you reach the end of the license, then type `agree` and enter.

####Clone the Repo

    git clone https://github.com/litographs/mac-dev-environment-setup.git
    cd mac-dev-environment-setup

####Install the Automated Way

    chmod +x setup.sh
    ./setup.sh

You will need to provide some inputs where asked.

####Install Sublime Text 3
<http://www.sublimetext.com/3>

Make sure your ~/Applications folder exists

    ln -s /Applications ~/Applications

Copy Sublime

    cp -R "Sublime Text.app" ~/Applications/

Allow opening of file in Sublime from the terminal

    ln -s "/Applications/Sublime Text.app/Contents/SharedSupport/bin/subl" /usr/local/bin/subl
    subl test.txt

__Replace default Sublime setup with Nick W's highly tweaked version__

    cat Sublime-Support.tar.part.* > Sublime-Support.tar
    mv Sublime-Support.tar "~/Library/Application Support/"
    cd "~/Library/Application Support/"
    tar -xvf Sublime-Support.tar
    rm Sublime-Support.tar

####Install Git from Github
<https://mac.github.com/>

    cp -R "GitHub.app" ~/Applications/

####Install iTerm2
<https://iterm2.com/downloads.html>

    cp -R "iTerm.app" ~/Applications/

__Iterm Prefs__

    cp com.googlecode.iterm2.plist ~/Library/Preferences/
    open "Iterm.app"

Hide/Show iTerm by pressing `CTRL + OPT + CMD + T`

####Install Postgresapp
<http://postgresapp.com/>

    cp -R "Postgres.app" ~/Applications/

####Install oh-my-zsh

    curl -L http://install.ohmyz.sh | sh

Close iTerm, reopen.

    open ~/Applications/iTerm.app

####Install Homebrew

    ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

__Debug homebrew__

    brew doctor
    brew update

If all is good, proceed to install packages

    brew install wget
    brew install imagemagick
    brew install python

####Install Node and npm

    brew install node

Install some node packages globally

    npm install -g less
    npm install -g jslint
    npm install -g jshint
    npm install -g bower

####Install Python Packages

    pip install --upgrade setuptools
    pip install virtualenv

__Install Virtualenvwrapper__

    pip install virtualenvwrapper

Add the following lines to ~/.zshrc or take the shortcut

Shortcut: `cat virtualenvwrapper-appendtext.txt >> ~/.zshrc`

    export WORKON_HOME=$HOME/.virtualenvs
    export PROJECT_HOME=$HOME/Devel
    source /usr/local/bin/virtualenvwrapper.sh

`workon` command will list available environments

    mkvirtualenv venv

Creates and enters an environment

__Install Pillow dependencies__

    brew install libtiff libjpeg webp little-cms2
    pip install Pillow

#####Install more python packages

    pip install reportlab
    pip install django
    pip install flask
    pip install requests


####Install Mysql

    brew install mysql
    unset TMPDIR
    mysql_install_db --verbose --user=`whoami` --basedir="$(brew --prefix mysql)" --datadir=/usr/local/var/mysql --tmpdir=/tmp

Test login

    mysql.server start
    mysql_secure_installation

####Install Flycut
<https://itunes.apple.com/us/app/flycut-clipboard-manager/id442160987?mt=12>

####Install Find Any File
<https://itunes.apple.com/us/app/find-any-file/id402569179?mt=12>

###Bonus Section
_Nick's Favorite Apps_

__Dropbox__ Sync your files to the cloud

__Better Touch Tool__ Bind a mouse/touchpad gesture to a keyboard shortcut or action. ie.. hide/show terminal

__1Password__ Password Management

__Fantastical__ Quickly view/add events to your calendar from the menu bar

__VLC__ Play any video format

__BetterSnapTool__ Window snapping

__Bartender__ Hide menu bar items

__Deliveries__ Package/Order Tracking cross platform

__Find Any File__ Find Files anywhere on your filesystem (Useful for debugging.)

__iStat Menus__ Show System Stats from the menu bar

__Mint Quickview__ Show your financial transactions/balances from the menu bar

__Screenflow__ Screen capture app

__Shortcat__ Click items/browse with your keyboard

__Transmit__ Best SFTP App

__Parallels__ My Favorite Virtualization Software

__Virtualbox__ Free VMs

__Mou__ Free Markdown Editor

__Hazel__ Automate tasks via "Watched Folders"


























