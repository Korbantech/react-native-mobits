//
//  EstacionamentoViewController.h
//  MobitsPlaza
//
//  Created by desenvolvedor.
//  Copyright 2011 Mobits. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface EstacionamentoViewControllerPai : UIViewController <UIPickerViewDataSource, UIPickerViewDelegate> {
    UIView *salvarEstacionamentoView, *mostrarEstacionamentoView;
    UIPickerView *pickerView;
    UILabel *andarLabel, *dataLabel, *voceEstacionouLabel, *infoAndar, *pisoAndar;
    UIImageView *imagemEstacionamento;
    UIView *fundoColorido;
    int selecionado;
}

@property (nonatomic, strong) IBOutlet UIView *salvarEstacionamentoView, *mostrarEstacionamentoView;
@property (nonatomic, strong) IBOutlet UIPickerView *pickerView;
@property (nonatomic, strong) IBOutlet UILabel *andarLabel, *dataLabel, *voceEstacionouLabel, *infoAndar, *pisoAndar;
@property (nonatomic, strong) IBOutlet UIImageView *imagemEstacionamento;
@property (nonatomic, strong) IBOutlet UIView *fundoColorido;
@property (nonatomic, strong) IBOutlet UIView *pagamentoView;
@property (nonatomic, strong) IBOutlet UIView *guardarVagaView;

- (NSString *)getTitulo;
- (void)exibirPrimeiraTela;
- (IBAction)salvar;
- (IBAction)LimparEstacionamento;
- (void)salvarData;
- (void)exibirPagamentoViewController:(UIViewController *)pagamentoViewController;
- (NSString *)obterDataSalvaInternacionalizada;
- (void)exibirConsultaTicketViewController;
- (void)configurarConsultaTicket:(NSLayoutConstraint *)constraint;

@end
