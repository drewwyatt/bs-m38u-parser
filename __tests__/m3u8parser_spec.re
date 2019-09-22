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

        test("#manifest.allowCache", () => {
          let p = M3u8Parser.make();
          expect(p.manifest.allowCache) |> toEqual(true);
        });
      }
    ),
  );