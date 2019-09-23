type manifest = {. "allowCache": bool};

module Parser = (T: {type t;}) => {
  [@bs.new] [@bs.module "m3u8-parser"] external make: unit => T.t = "Parser";
  [@bs.send.pipe: T.t] external push: string => unit = "push";
  [@bs.send.pipe: T.t] external end_: unit => unit = "end";
  [@bs.get] external manifestGet: T.t => manifest = "manifest";
};

type t;
include Parser({
  type nonrec t = t;
});