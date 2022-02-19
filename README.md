# beachmaster
Beachmaster Linux Distro

## Not done.
This Linux Distribution is not done at all and should **NOT** be used in any capacity.

## Installing

### Package Manager
(As root)\
Installing: 
```
git clone https://github.com/seals-are-bouncy/beachmaster.git
cd beachmaster
make
make install
```
Configuring:
```
useradd -r -m -s /bin/sh beach
mkdir /etc/beach/
touch /etc/beach/installed
touch /etc/beach/users
touch /etc/beach/manifest
mkdir /var/cache/beach/
mkdir /var/cache/beach/distfiles/
mkdir /var/cache/beach/work/
```

### Distribution
How to install beachmaster. 
1) Boot into a minimal installation CD.
2) curl -sSL https://raw.githubusercontent.com/SirObby/beachmaster/main/install.sh | bash