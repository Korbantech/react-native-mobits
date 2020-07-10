import { NativeModules } from 'react-native';

type MobitsType = {
  multiply(a: number, b: number): Promise<number>;
};

const { Mobits } = NativeModules;

export default Mobits as MobitsType;
