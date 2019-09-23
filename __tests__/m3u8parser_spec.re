open Jest;

let () =
  describe(
    "m38u-parser",
    ExpectJs.(
      () => {
        test("#make", () =>
          expect(M3u8Parser.make()) |> toBeTruthy
        );

        test("#push", () =>
          expect(M3u8Parser.make() |> M3u8Parser.push("Hey")) |> toBeFalsy
        );

        test("#end", () =>
          expect(M3u8Parser.make() |> M3u8Parser.end_()) |> toBeFalsy
        );

        test("#manifest", () =>
          expect(M3u8Parser.make() |> M3u8Parser.manifestGet) |> toBeTruthy
        );

        test("#manifest#allowCache", () => {
          let manifest = M3u8Parser.make() |> M3u8Parser.manifestGet;
          expect(manifest##allowCache) |> toEqual(true);
        });
      }
    ),
  );