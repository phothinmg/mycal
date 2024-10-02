export = Mycal;
export as namespace mycal;
declare namespace Mycal {
  declare function toJdn(
    year: number,
    month: number,
    date: number,
    ct: number
  ): number;
}
