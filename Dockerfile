FROM envoyproxy/envoy-build:f60886c04253d9a096503b949696cbdc8f82fa4d as builder

WORKDIR /workdir
COPY client.cc .
RUN g++ client.cc -o client 

FROM ubuntu:18.04
COPY --from=builder /workdir/client .
CMD ["./client"]
