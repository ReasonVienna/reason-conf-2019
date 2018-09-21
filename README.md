# ReasonConf 2018

## Design mockup

https://www.figma.com/file/fVvLR4MkLxslAkTsl2En07TY/Reason-Conf-2018

## Develop

Install all depedencies via

```sh
npm install
```

Run BuckleScript in one Shell

```sh
npm run bs:start
```

Run Gatsby in another Shell

```sh
npm start
```

Visit `http://localhost:3000` in your browser

## genFlow Setup

We use [genFlow](https://github.com/cristianoc/genFlow) to automatically generate interop wrappings for ReasonReact components -> React components, to set things up, please follow these steps:

```
# Use whatever base directory you feel like
cd ~/Projects
git clone https://github.com/cristianoc/genFlow.git
cd genFlow

# Now install the build toolchain and build the genFlow binary
npm install
npm run build

# Your binary should now be located in ~/Projects/genFlow/lib/bs/native/genflow.native
# Please remember the path (maybe store it in some env variable (PATH) or such)
# To make BuckleScript use this binary, you need to set following env variable in the base of this project before running (`npm run bs:start`):
export BS_CMT_POST_PROCESS_CMD="/Users/me/Projects/genFlow/lib/bs/native/genflow.native --setProjectRoot $PWD"
```

## Build

```sh
# If you want to use auto generated bindings
export BS_CMT_POST_PROCESS_CMD="/Users/me/Projects/genFlow/lib/bs/native/genflow.native --setProjectRoot $PWD"
npm run bs:build && npm run build
```
