PLATFORM='linux'
UNAMESTR=`uname`

if [ "$UNAMESTR" == 'Linux' ]; then
   PLATFORM='linux'
elif [ "$UNAMESTR" == 'Darwin' ]; then
   PLATFORM='macos'
fi


echo "Downloading genFlow for platform '$PLATFORM' in node_modules/.bin/ directory..."

curl -L https://github.com/cristianoc/genFlow/releases/download/v0.8.0/genflow-$PLATFORM.tar.gz | tar xz -C node_modules/.bin
