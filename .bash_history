ls
ls -la
ping google.com
vi README 
ls -a
git init
rmdir .git
rm -rf .git
cd os161/
./configure --ostree=$HOME/os161/root --toolprefix=sos-
cd kern/conf
./config ASST0
cd ../compile/ASST0
pmake depend 
pmake
pmake install
cd ~/os161/
pmake
cd root
cp ~/sys161/sys161.conf sys161.conf
sys161 kernel-ASSTO
sys161 kernel-ASST0
quit
