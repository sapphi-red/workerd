# unsafe

## Running

```
$ bazel run //src/workerd/server:workerd -- serve $(pwd)/samples/unsafe/config.capnp
$ curl localhost:8080 -X POST
9
```
