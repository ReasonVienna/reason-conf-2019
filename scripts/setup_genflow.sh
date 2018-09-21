PLATFORM='linux'
UNAMESTR=`uname`

if [ "$UNAMESTR" == 'Linux' ]; then
   PLATFORM='linux'
elif [ "$UNAMESTR" == 'Darwin' ]; then
   PLATFORM='macos'
fi


echo "Downloading genFlow for platform '$PLATFORM' in vendor/ directory..."

curl -L https://github.com/cristianoc/genFlow/releases/download/v0.8.0/genflow-$PLATFORM.tar.gz | tar xz -C vendor
