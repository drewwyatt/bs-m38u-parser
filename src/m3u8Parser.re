type track = {
  .
  "autoSelect": bool,
  "defualt": bool,
  "language": option(string),
  "url": string,
};

type trackLanguage = Js.Dict.t(track);
type group = Js.Dict.t(trackLanguage);
type mediaType = Js.Dict.t(group);

type manifest = {
  .
  "allowCache": bool,
  "mediaGroups": option(mediaType),
};

module Impl = (T: {type t;}) => {
  [@bs.new] [@bs.module "m3u8-parser"] external make: unit => T.t = "Parser";
  [@bs.send.pipe: T.t] external push: string => unit = "push";
  [@bs.send.pipe: T.t] external end_: unit => unit = "end";
  [@bs.get] external manifestGet: T.t => manifest = "manifest";

  let push = (playlist: string, self: T.t) => {
    push(playlist, self);
    self;
  };

  let end_ = (self: T.t) => {
    end_((), self);
    self;
  };
};

type t;
include Impl({
  type nonrec t = t;
});