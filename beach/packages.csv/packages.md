# packages.csv
packages.csv is the mastermind of the beach package manager.
Here's a more indepth explanation of how it works.
Incase you want to make your own package for the beach package manager (now referred to as, as bpm)
You need this folder.
Just add your entry to packages.csv, then compress this folder to a tar.gz folder
**THIS FILE SHALL NOT BE REMOVED**
## Entries
packages.csv is an excel sheet, but you don't need microsoft excel to modify it, any text editor will do.
Entries follow this format:
"package-name,author,version,day,month,year,archive,install,information"
An example of format is like this:
"example-pkg,sirobdidian,0.0.1,26,12,2021,example-pkg-sirobsidian.tar.gz,install.sh,information.csv"
Pretty self-explanatory.\
See the example-pkg for an example of their csv and configuration files.
## Compressing
tar -czvf packages.csv.tar.gz packages.csv/