# Welcome to our Development Team!
This is our development repository. This is what the members of and contributors to our organization use to actively maintain the code for our site.

## Table of Contents
1. [Setting Up Your Local Environment](#setting-up-your-local-environment)
    1. [Linux](#linux)
    2. [Mac OS and Windows](#mac-os-and-windows)
2. [Installing Drupal](#installing-drupal)
    1. [Git](#git)
    2. [Composer](#composer)
        1. [Advanced](#advanced)
    3. [Drush](#drush)
    4. [Drupal Setup](#drupal-setup)
3. [Our Workflow](#our-workflow)
    1. [Pulling Updates](#pulling-updates)
    2. [Pushing Updates](#pushing-updates)
    3. [General](#general)
4. [Theming](#theming)

## Setting Up Your Local Environment
In order to get Drupal 7 up-and-running on your local machine, you will have to set up your local environment by installing some basic server technologies. The main ones required by Drupal are known collectively as the **AMP** stack. AMP stands for **Apache**, a web server; **MySQL**, a database management system; and **PHP**, a standard backend language. Together, these technologies manage most of the backend for typical websites. Variations of the AMP stack are supported by most modern and widely distributed operating systems, giving you the freedom to work in whichever environment you are most comfortable in. However, each environment comes with a unique set of obstacles that you may encounter during the installation or development stages of the process. You should consider these when deciding which is the best solution for you.

### Linux
Drupal works best on a **Linux** operating system, and as such, working in Linux is the recommended option. Linux can be installed **_beside_** Windows or Mac via a dual-boot solution. It can also be installed **_within_** Windows or Mac through a virtual machine (such as VirtualBox). Note that running an operating system within another (such as through a virtual machine) can be intensive for some computers and will always be less efficient than running Linux as a stand-alone or dual-booted operating system. Still, it may be a viable option for someone with a decently performing computer not looking to mess with their boot configurations.

There are plenty of Linux distributions to choose from. **Ubuntu** is one of the more widely used ones, but there are also many other distros available for free online.

Installing a **LAMP** (Linux AMP) stack is fairly straightforward for those familiar with Linux. For those unfamiliar, it involves typing commands into a _terminal_ to install the different components. It is highly recommended that you learn the basic commands to navigate through Linux's filesystem as well as some commonly used _tty_ programs. The time afforded by command-based tools is well worth the effort put into learning them. As a good start, learn how to install a LAMP stack by searching online for the necessary commands. Because Linux distro's use different packaging systems, these commands may vary based on your installation.

### Mac OS and Windows
AMP variants are available in other operating systems, including **WAMP** (Windows AMP), **MAMP** (Mac AMP), and **XAMPP** (the extra 'P' is for _Perl_). Some, including XAMPP, are available in both environments. Installers can be found to install all the necessary components at once. Note that not all of the underlying components are supported to the same extent as their Linux counterparts, and that the programs may work differently, lack certain features, or encounter environment-specific errors.

## Installing Drupal
To practice with a Drupal sandbox, go to [Drupal.org][drupal] to download a basic Drupal environment and go through the installation instructions to get it working. The sandbox will allow you to test modules and themes and be able to experiment with Drupal core.

### Git
Once you are comfortable with the basics of Drupal, you can begin to work on our development project. You'll need to have **git** installed on your local machine. You should be able to install git from the _command-line_ (terminal) on Linux and Mac OS. For Windows, you can use **git bash** (a bash shell port with support for a small set of bash commands), any of the Linux distros available on the _Windows Store_ as part of the **Windows Subsystem for Linux** (WSL) project, or the Windows **GitHub Desktop App** (which offers a GUI interface for those not familiar or comfortable with the git shell-commands). To download our project, you will have to _clone_ it from this repository.

### Composer
Following Drupal's recommended development setup, we will be using **composer** to manage the packages used for our project, rather than installing/updating anything from the user interface. You will have to install composer _globally_ on your machine. You can see that after cloning our repository, _composer.json_ and _composer.lock_ files exist on the project root-directory. The .json file lists the required packages and their version constraints for running our site, while the .lock file keeps track of the actual versions of those packages being used. You won't have to modify these files directly as you will be using commands to add, update, and remove packages; and yes, you can do this in any environment. You may also notice that the .json file lists the default directories for Drupal packages, including separate directories for modules, themes, profiles, etc. Contributed packages (**contrib**) are also separated from **custom** packages. For our purposes, custom packages include our own original packages, unsupported versions of contrib packages, as well as modified contrib packages. Custom and modified contrib packages cannot be tracked by composer conventionally as they are not included in Drupal's nor a 3rd-party's package-directories, but they can be tracked by adding their repositories as package-directories. Some custom packages we will track through composer, but most we track through git as part of our project.

To add a package as a dependency and install it, use the 'require' command:

`composer require <vendor>/<package>[:<version_constraint>]`

For Drupal packages, the vendor is 'drupal'. You are not usually required to include a version constraint, as denoted by the square-bracket syntax. The packages we have used have been listed in our .json file after running 'require'. In order to install them on your machine, you will need to run

`composer install`

from within the project root-directory.

#### Advanced
There are times, you may want to modify the _composer.json_ file directly. If you want to add a project that cannot be found in a package-directory online, and the package does not include a _composer.json_ file, you can add the repository to the .json file and then require the package. You can also add a package-directory that contains multiple packages which you can then require as dependencies. I leave it up to you to find out how to do this, but you may find some examples in the project's root _composer.json_ file as well.

You may have noticed a separate _composer.json_ file within the _sites/all/libraries/_ directory. We plan to use this to keep track of third-party library packages that need to be added to that same directory. Through composer's merging extension, we are able to install these packages from the project-root .json file to the same .lock file. It may require a few extra steps to update the .lock file, but once done, they will be installed like all the other packages on the root .json file. Since composer does not allow us to download these packages to the correct directory, they are simply added to composer's default _vendor/_ directory within the project-root. We've included a script with the git repository, which composer uses to create symlinks for these in the proper directory, achieving the same behavior (this assumes that the packages do not need to be renamed, but so far this has not been an issue). Any packages that cannot be added through composer, or would be too difficult to add through composer are simply included as-is on the git repository. Note that if you do this, you must modify the .gitignore file under _sites/_ to not ignore this specific package.

As an example of how to require a new library package in this _composer.json_ file, `cd` into the _sites/all/libraries/_ directory and run:

`composer require <vendor>/<package>[:<version_constraint>] --no-update`

The `--no-update` option will make sure that a separate .lock file is not created, so that you actually install the dependencies through the project-root .lock file. To update the .lock file, `cd` back to the project-root and run:

`composer update --lock`

### Drush
We will be using **drush** to manage Drupal configurations from the command-line. This is more efficient than using the UI and we encourage you to learn some of the commands to apply to your own environment. Though we include a local drush package, we also recommend installing drush _globally_ through composer, as you can add it to your **path** environmental variable so that you can use it from any directory, and it will look for a site-local drush when one is available. This is especially useful when you are managing different projects that require different versions of drush, for instance a site running D7 vs. a site running D8.
**Note:** drush 9 does not work with D7, so install drush 8 globally and it will use the correct site-local version for both D7 and D8 (it will correctly switch to drush 9 on a D8 site that uses it).

To download and install drush through composer, use 'require' as before, apply the 'global' modifier, and specify that version 8.

`composer global require drush/drush:~8.0`

### Drupal Setup
Now you can start the Drupal installation. Copy the _default.settings.php_ file in _sites/default/_ to a file named _settings.php_ in the same directory. Then you should be able to get on your browser and type in the address, which will probably be _localhost_ if your apache server is running on your local machine. This should redirect you to _<host_name>/core/install.php_ to begin the installation process. Follow the steps presented to finish the installation. Once done, you will need to add an extra line to your _settings.php_ file (if not present):

`$conf['composer_autoloader'] = DRUPAL_ROOT . '/vendor/autoload.php';`.

This changes the default configuration for the 'composer_autoloader' module and tells it where to find the composer _autoload.php_ file.

## Our Workflow
Maintaining our site requires that everyone actively communicate with each other to discuss issues, solutions, and to coordinate tasks. Forgetting steps to our process along the way can easily lead to some nasty errors to resolve, which would affect not only you, but other team members as well. In the following sections, we detail the procedures we use to maintain consistent views across all of our environments.

### Pulling Updates
1. Pull code and configuration changes from GitHub:

    `git pull origin master`

2. If any changes have been made to the _composer.json_ file, you will need to download, remove, or update the necessary packages based on the changes. Luckily, you can do this by running one command:

    `composer install`

3. Assuming you and others have properly updated the development site, you will need to retrieve those updates and integrate them into your local environment. This requires two steps:

    1. Synchronize your local _sites/default/files/_ directory with that of the development server.
    
        You can use `sftp`, `scp`, or any other program that allows you to remotely access the server and retrieve the files. Note that this requires you to have access to our remote server; consult members of our team to find out how to get this. Here's how you could use the `scp` command to do this.
        
        `scp -r <remote_host>:<path_to_site_root>/sites/default/files <local_path_to_site>/sites/default`
    
    2. Obtain an updated copy of the database from the development site's server.
    
        You should create a database dump/export and download it. Note that this requires you to have access to our remote database, and you should consult members of our team to get this. On your local machine, drop all the tables in your project's database. You can also drop the database entirely and recreate it, but remember to once again give all privileges to the database user for your site. Finally, import the database export/dump into your local database. Note that we may be using cron jobs to automatically create database exports/dumps on our server at certain intervals. Consult with us to find out where to find these.
    
    **Note:** We recommend you use command-line tools whenever possible to carry out a task. Sometimes we don't have access to run certain commands, especially on our remote server or to connect to our remote server in certain ways. We've had success with drush's `rsync` command to update local filesystems, mainly the _sites/default/files/_ directory. You would use this command in place of `sftp` or `scp`. The advantage to using `rsync` is that it does not copy all of the contents of a directory, but looks for which files/directories have been modified or added since you last ran the command, saving lots of time when there are many files to copy over. Here's an example of how to use this command:
    
    `drush rsync <remote_host>:<absolute_path_to_site_root>/sites/default/files <absolute_path_to_site>/sites/default/files`
    
    One command you can try using to update your local database is drush's `sql-sync` command. We have had some trouble getting this specific command to work, but feel free to try it out at least once.
    
    Both of these drush commands support aliases, allowing you to reference a specific host and file/directory without constantly typing out or remembering the absolute paths to those files. If you're interested in setting this up and using these commands, have a look at these useful links:
    * https://www.drupal.org/node/1401522
    * https://dev.acquia.com/blog/use-drush-to-sync-your-drupal-installations-between-multiple-environments/06/04/2016/10236

### Pushing Updates
1. If you're adding a new package that can be tracked by composer, make sure to update the _composer.json_ file by adding the package as a dependency:

    `composer require <vendor>/<package>[:<version_constraint>]`

    Other useful composer commands you might want to look into: 'update' and 'remove'. If you need to add a third-party library, refer back to the [Installing Drupal -> Composer -> Advanced](#advanced) section above.

2. Now stage your changes, commit them, and push them onto our repository. If you're using the command-line for git, use the following commands:

    ```
    git add .
    git commit -m "some useful message"
    git push origin master
    ```

3. If any changes were made to configuration settings, including enabling/disabling of modules or themes, you will need to manually recreate those changes on the development site. In certain cases, such as when adding a new view, you can export the change (in this case, the view) and save the export, then import those changes to the development site. In general however, once you've tested-out the basic functionality of a new feature and determined that it is safe to use, you can proceed to make the necessary changes directly on the server, without having to do them on your local environment first. This reduces unnecessary duplication of your work and saves time. The changes will eventually make it to your local environment when you choose to update it.

### General
Think of your local setup as an environment to test out functionality and basic configuration settings, and the server as the place you will do more comprehensive testing on. Additionally, any changes made to code or to the file system should be done locally first, tested, and then committed through git. Changes to content or the database are better done directly on the server, but make sure you understand what these changes are by testing on your local environment first.

## Theming
We use a customized version of the [Drupal Bootstrap][bootstrap] theme. We inherit the Bootstrap framework as well as some useful styling, code, and templates. Ontop of these, we have some of our custom files that add to or modify these Bootstrap defaults in order to fine-tune the appearance of our site to our liking. These changes are tracked by our git repository. The _css/_ and _js/_ directories contain front-end stiling sheets and scripts, respectively. The _templates/_ directory contains our custom templates as well as modified templates based on the Bootstrap defaults. Templates are php files that generate html for pages based on some variables in your theme's settings as well as the content for the specific page. The _template.php_ file mostly contains preprocessing functions we have added in order to dynamically link styling and scripts based on **Content Type** or **Node ID (nid)**. It will be used for most theme-related code, but some code will be separated to different files within the _templates/_ directory. The theme's .info file can link css and js statically, as well as define new regions for the theme, and allows you to configure default settings for your theme as well. You can find our theme inside the _sites/all/themes/custom/_ directory.

For more information about Bootstrap, the Bootstrap theme, and sub-theming with Bootstrap, checkout the following links:
* https://drupal-bootstrap.org/api/bootstrap/docs%21Getting-Started.md/group/getting_started/7
* https://drupal-bootstrap.org/api/bootstrap/docs%21subtheme%21README.md/group/subtheme/7

For general information about theming and sub-theming, checkout these tutorials (you have to have a subscription to view them all, but you can learn alot just from the free ones): https://buildamodule.com/video/drupal-7-theming-essentials-important-drupal-theming-concepts-what-is-the-difference-between-designing-theming-and-coding-and-why-do-they-overlap-so-much?pc=THEMING7645423

[drupal]: https://www.drupal.org
[bootstrap]: https://www.drupal.org/project/bootstrap
