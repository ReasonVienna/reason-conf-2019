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
# This will download genflow.native and put it in `vendor/genflow.native`
# (You will only need to run this script again, when upgrading the binary)
. scripts/setup_genflow.sh

# Export this env variable before running the BuckleScript compiler (only in project root directory!):
export BS_CMT_POST_PROCESS_CMD="$PWD/vendor/genflow.native --setProjectRoot $PWD"
```

## Build

```sh
# If you want to use auto generated bindings
export BS_CMT_POST_PROCESS_CMD="$PWD/vendor/genflow.native --setProjectRoot $PWD"
npm run bs:build && npm run build
```
