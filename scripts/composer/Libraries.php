<?php

namespace DrupalProject\composer;

use Composer\Script\Event;
use DrupalFinder\DrupalFinder;
use Symfony\Component\Filesystem\Filesystem;
use Webmozart\PathUtil\Path;

function rel($path) {
  if ($path == '')
    return '.';
  return $path; 
}

class Libraries {
  public static function createSymlinks(Event $event) {
    $fs = new Filesystem();
    $drupalFinder = new DrupalFinder();
    $drupalFinder->locateRoot(getcwd());
    $drupalRoot = rel($drupalFinder->getDrupalRoot());
    $composerRoot = rel($drupalFinder->getComposerRoot());
    $vendorDir =  Path::makeRelative($event->getComposer()->getConfig()->get('vendor-dir'), realpath($composerRoot));

    $lib = $drupalRoot . '/sites/all/libraries';
    $json = file_get_contents($lib . '/composer.json');
    $json_array = json_decode($json, true);

    $symlinks = array();
    foreach ($json_array['require'] as $key => $val) {
      $symlinks[$key] = preg_split("#/#", $key)[1]; 
    }

    if (isset($json_array['extra'])) {
      foreach ($json_array['extra']['aliases'] as $key => $val) {
        $symlinks[$key] = $val;
      }
    }

    foreach ($symlinks as $key => $val) {
      $lnk = $lib . '/' . $val;
      if ($fs->exists($lnk)) {
        continue;
      }

      $target = $composerRoot . "/$vendorDir/$key";
      symlink(Path::makeRelative($target, $lib), $lnk);
    }
  }
}
