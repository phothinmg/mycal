import { mycal } from "../src/index.js";
import assert from "node:assert";
import test from "node:test";

test("Julian Day Number Converter", async (t) => {
  const jdn = mycal.toJdn(2024, 10, 2, 2);
  await t.test("jdn", () => {
    assert.deepEqual(jdn, 2460586);
  });
});
