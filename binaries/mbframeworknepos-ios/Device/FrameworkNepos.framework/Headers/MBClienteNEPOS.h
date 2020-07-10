//
//  MBClienteNEPOS.h
//  FrameworkNepos
//
//  Created by  on 05/07/19.
//  Copyright © 2019 Mobits. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MBClienteNEPOS : NSObject {
    
}

- (id)initWithNome:(NSString *)nome sobrenome:(NSString *)sobrenome documento:(NSString *)documento celular:(NSString *)celular email:(NSString *)email;

@property (nonatomic, strong) NSString *nome;
@property (nonatomic, strong) NSString *sobrenome;
@property (nonatomic, strong) NSString *documento;
@property (nonatomic, strong) NSString *celular;
@property (nonatomic, strong) NSString *email;


@end

NS_ASSUME_NONNULL_END
