# REX1727-PowerUp

The 2018 Power Up FRC codebase for REX 1727.

## Building

There are multiple ways to build the project here.

On linux, the bash scripts provided in the root of the directory will automate the build process.

Issue

```
./build.sh && ./deploy.sh
```

to build and deploy to the roboRIO.

Note that `build.sh` has two targets - opt and debug. The former is compiled without debug info and with `-O2`, and the latter with `-O0 -Og -g3`
