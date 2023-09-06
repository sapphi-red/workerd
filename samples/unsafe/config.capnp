using Workerd = import "/workerd/workerd.capnp";

const helloWorldExample :Workerd.Config = (
  services = [ (name = "main", worker = .helloWorld) ],
  sockets = [ ( name = "http", address = "*:8080", http = (), service = "main" ) ]
);

const helloWorld :Workerd.Worker = (
  modules = [
    (name = "worker", esModule = embed "worker.js")
  ],
  compatibilityDate = "2023-02-28",
  compatibilityFlags = ["unsafe"]
);
