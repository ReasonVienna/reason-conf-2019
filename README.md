# ReasonConf 2018

## Design mockup

https://www.figma.com/file/fVvLR4MkLxslAkTsl2En07TY/Reason-Conf-2018

## Develop

Install all depedencies via

```sh
npm install

# This will download genflow.native and put it in `vendor/genflow.native`
# (You will only need to run this script again, when upgrading the binary)
./scripts/setup_genflow.sh
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

## Build

```sh
npm run bs:build && npm run build
```
