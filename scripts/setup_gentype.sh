PLATFORM='linux'
UNAMESTR=`uname`

if [ "$UNAMESTR" == 'Linux' ]; then
   PLATFORM='linux'
elif [ "$UNAMESTR" == 'Darwin' ]; then
   PLATFORM='macos'
fi


echo "Downloading genType for platform '$PLATFORM' in node_modules/.bin/ directory..."

curl -L https://github.com/cristianoc/genType/releases/download/v0.15.0/gentype-$PLATFORM.tar.gz | tar xz -C node_modules/.bin

echo "Test run gentype:"
node_modules/.bin/gentype.native --help
