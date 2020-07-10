//
//  MBFrameworkNEPOS.h
//  FrameworkNepos
//
//  Created by  on 08/07/19.
//  Copyright © 2019 Mobits. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MBClienteNEPOS.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MBFrameworkNEPOSDelegate <NSObject>

- (void)sucessoAoRealizarPagamentoDoTicket:(NSString *)numeroTicket saidaAteData:(NSString *)saidaAteData tempoPermanencia:(NSString *)tempoPermanencia horaPagamento:(NSString *)horaPagamento valorPagamento:(NSString *)valorPagamento numeroRps:(NSString *)numeroRps serie:(NSString *)serie nomeGateway:(NSString *)nomeGateway operador:(NSString *)operador garagem:(NSString *)garagem endereco:(NSString *)endereco cnpj:(NSString *)cnpj;

- (void)sucessoAoAutenticarComToken:(NSString *)token codigo:(NSString *)codigo chave:(NSString *)chave;

- (void)erroAoRealizarPagamento:(NSString *)mensagem;

- (void)erroAoAutenticar:(NSString *)mensagem;

- (void)cartaoGravadoComBandeira:(NSString *)bandeira ultimosDigitos:(NSString *)digitos;

@end

@protocol MBFrameworkNEPOSAnalyticsDelegate <NSObject>

- (void)exibiuTela:(NSString *)tela usandoCartaoGravado:(BOOL)cartaoGravado codigoNEPOS:(NSString *)codigoNEPOS ticket:(NSString *)ticket;
- (void)realizouEventoNaCategoria:(NSString *)categoria acao:(NSString *)acao label:(NSString *)label cartaoGravado:(BOOL)cartaoGravado codigoNEPOS:(NSString *)codigoNEPOS ticket:(NSString *)ticket;

@end

@interface MBFrameworkNEPOS : NSObject {
    
}

@property (nonatomic, strong) MBClienteNEPOS *cliente;
@property (nonatomic, strong) NSString *token;
@property (nonatomic, strong) NSString *chave;
@property (nonatomic, strong) NSString *idCliente;
@property (nonatomic, strong) NSString *trackingId;
@property (nonatomic, strong) NSNumber *idGaragem;
@property (nonatomic, weak) IBOutlet NSObject <MBFrameworkNEPOSDelegate> *delegate;
@property (nonatomic, weak) IBOutlet NSObject <MBFrameworkNEPOSAnalyticsDelegate> *delegateAnalytics;

+ (id)sharedMBFrameworkNEPOS;

- (UIViewController *)iniciarComGaragem:(int)garagemId cliente:(MBClienteNEPOS *)cliente trackingId:(NSString *)trackingId;
- (UIViewController *)iniciarComGaragem:(int)garagemId token:(NSString *)tokenNepos chave:(NSString *)chaveNepos codigo:(NSString *)codigoNepos trackingId:(NSString *)trackingId;
- (NSString *) codigoCliente;
+ (UIFont *) fonteDoTitulo;
+ (UIColor *) corDoTitulo;
@end

NS_ASSUME_NONNULL_END
