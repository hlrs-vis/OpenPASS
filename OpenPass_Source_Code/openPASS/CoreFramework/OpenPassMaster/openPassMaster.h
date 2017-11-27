/** \addtogroup OpenPassMaster
* @{
*
* \section masterDesc Detailed Description
* This is the master module of the framework and it contains the main entry point
* of the framework.
*
* These executeable is started by the GUI with or without an argument to set the
* frameworkConfiguration.xml file.
* It reads the frameworkConfigarion.xml and saves all options and information.
* Following this a slave executable is started with the options and information
* as agrument.
*
* \section Input arguments
* arguments | meaning
* -----|---------
* -frameworkConfigFile | Path to framework configuration file. Working directory and "frameworkConfig.xml" by default.
*
* \section Output files
* file | description
* -----|---------
* logMaster.txt | This file contains all log messages depending on the logLevel. Path and name are specified in frameworkConfig.xml.
*
* @} */