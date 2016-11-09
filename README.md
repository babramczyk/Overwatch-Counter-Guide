##CS368 Group Project

#### Running the project
* Download Qt
* Depending on your version of Xcode you might need to follow [this post](http://stackoverflow.com/questions/33728905/qt-creator-project-error-xcode-not-set-up-properly-you-may-need-to-confirm-t) to get Qt to play nice on Mac.
* open the project in Qt
* `cmd + r` to run the application

####MySQL connectors 
* Follow [Qt's directions](http://doc.qt.io/qt-5.7/sql-driver.html) for building the MySQL plugin.
* A couple of things that tripped me up
	* Make sure qmake is referenced in the `PATH` variable
	* Make sure the location of MySQL on your machine matches the location they specified in the command i.e. `/usr/local/include`. (Homebrew install location is usually `/usr/local/Cellar/mysql/<version>...`)