import { NativeModules, NativeEventEmitter } from 'react-native';
import Emitter from '@cookiex/emitter';

const emitter = new Emitter<MobitsEvents>();

const nativeEmitter = new NativeEventEmitter(NativeModules.Mobits);

const middleware = (event: keyof MobitsEvents) => (...args: any[]) => {
  if (Array.isArray(args[0])) emitter.emit(event, ...args[0]);
  else emitter.emit(event, ...args);
};

nativeEmitter.addListener('payment', middleware('payment'));
nativeEmitter.addListener('payment-error', middleware('error'));
nativeEmitter.addListener('auth', middleware('auth'));
nativeEmitter.addListener('auth-error', middleware('error'));
nativeEmitter.addListener('card', middleware('card'));
nativeEmitter.addListener('open', middleware('open'));
nativeEmitter.addListener('event', emitter.emit);
nativeEmitter.addListener('start', () => console.log('start mobits framework'));

emitter.on({
  auth: console.log,
  card: console.log,
  error: console.log,
  open: console.log,
  payment: console.log,
});

interface Mobits {}

export interface MobitsClient {
  firstName: string;
  lastName: string;
  document: string;
  phone?: string;
  email?: string;
}

const placeholderClient = { phone: '', email: '' }

export interface MobitsEvents {
  payment(
    ...args: [string, string, string, string, string, string, string]
  ): void;
  auth(token: string, code: string, key: string): void;
  error(error: Error): void;
  card(...args: [string, string]): void;
  open(...args: [string, string, string, string]): void;
  [key: string]: (...args: any[]) => void;
}

export const open = (garage: number, track: string, client: MobitsClient) =>
  new Promise<Emitter<MobitsEvents>>((resolve, reject) => {
    NativeModules.Mobits.open(garage, track, Object.assign( {}, placeholderClient, client )).then(
      () => resolve(emitter),
      reject
    );
  })

const Mobits = { open };
// namespace Mobits {
//   export interface Client extends MobitsClient {}
//   export interface Events extends MobitsEvents {}
// }

export default Mobits;
